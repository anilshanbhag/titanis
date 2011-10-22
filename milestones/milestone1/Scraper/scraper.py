#!/usr/bin/python

import re
import robotparser
import urllib
import urllib2
import urlparse
import pickle
from subprocess import check_output as call

class Scraper :
	def __init__(self):
		self.startUrl = "http://www.reddit.com/r/programming/"
		# Set of unique urls already crawled
		self.set = set()
		# Queue of urls to be crawled
		self.q = []
		# Dictionary of robots.txt files
		self.robots = {}
		# Count of sites scraped
		self.count = 0
		# Robots file parser
		self.rp = robotparser.RobotFileParser()

	def saveState(self):
		f = open('queue.txt','w')
		pickle.dump(self.q, f)
		f.close()
		f = open('set.txt','w')
		pickle.dump(self.set,f)
		f.close()
		f = open('robotslog.txt','w')
		pickle.dump(self.robots,f)
		f.close()
	
	def loadState(self):
		f = open('queue.txt','r')
		self.q = pickle.load(f)
		f.close()
		f = open('set.txt','r')
		self.set = pickle.load(f)
		f.close()
		f = open('robotslog.txt','r')
		self.robots = pickle.load(f)
		f.close()
		
	def run(self):
		try:
			# Add the start url into the queue
			self.q.append(self.startUrl)
			self.set.add(self.startUrl)
			## While queue is not empty
			## Keep scraping pages
			while self.q:
				if(len(self.q[0]) > 40):
					del self.q[0]
					continue
				print self.q[0]
				dump = self.getDump(self.q[0])
				if (dump):
					self.saveDump(self.q[0], dump)
					self.scrapeURLs(self.q[0])
				del self.q[0]
		except KeyboardInterrupt:
			self.saveState()
			
	def getRobotsFile(self,host):
		url = "http://" + host + "/robots.txt"
		opener = URLopener()
		f = opener.open(url)
		lines = [line.strip() for line in f]
		f.close()
		errcode = opener.errcode
		if errcode in (401, 403):
			self.robots[host] = ['User-agent: *','disallow: /']
		elif errcode >= 400:
			self.robots[host] = ['']
		elif errcode == 200 and lines:
			self.robots[host] = lines
			
	def getDump(self,url,flag = 1):
		try:
			if flag:
				host = urlparse.urlparse(url)[1]		
				if not host in self.robots:
					self.getRobotsFile(host)
					self.parserReInit(host)
					self.rp.parse(self.robots[host])
			if self.rp.can_fetch('*',url):
				return urllib2.urlopen(url,timeout = 2).read()
			else:
				return ''
		except:
			print url + " failed"
			return ''
	
	def parserReInit(self,host):
		self.rp.entries = []
		self.rp.default_entry = None
		self.rp.disallow_all = False
		self.rp.allow_all = False
		self.rp.set_url("http://" + host + "/robots.txt") 
		self.rp.last_checked = 0
		
	def scrapeURLs(self,url):
		# to get domain '(http:\/\/.*?)[\/|#|\?].*'
		dump = call(["lynx","-dump","-hiddenlinks=ignore",'Repository/' + urllib.urlencode({'':url})[1:] + '.html'])
		links = re.findall('http:\/\/.*?[\/|#|\?].*',dump)
		for link in links:
			if 'localhost' not in link and link not in self.set:
				self.set.add(link)
				self.q.append(link)
	
	def saveDump(self,url,dump):
		f = file('Repository/' + urllib.urlencode({'':url})[1:] + '.html', 'w')
		f.write(dump)
		f.close()
		print "Completed " + url
	
class URLopener(urllib.FancyURLopener):
    def __init__(self, *args):
        urllib.FancyURLopener.__init__(self, *args)
        self.errcode = 200

    def prompt_user_passwd(self, host, realm):
        ## If robots.txt file is accessible only with a password, pretend missing
        return None, None

    def http_error_default(self, url, fp, errcode, errmsg, headers):
        self.errcode = errcode
        return urllib.FancyURLopener.http_error_default(self, url, fp, errcode,
                                                        errmsg, headers)
                                   
if __name__ == '__main__':
	scraper = Scraper()
	scraper.run()
