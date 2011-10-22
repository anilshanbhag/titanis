# USE make all to compile indexer
CC=g++
CFLAGS=-c -Wall

all:repoReader.o docIndex.o indexer.o fIndex.o URLResolver.o pageRank.o iIndex.o tokenizer.o stopwords.o
	$(CC) repoReader.o docIndex.o indexer.o fIndex.o URLResolver.o pageRank.o iIndex.o tokenizer.o stopwords.o -o indexer
	
repoReader.o: repoReader.cpp
	$(CC) $(CFLAGS) repoReader.cpp
	
docIndex.o: docIndex.cpp
	$(CC) $(CFLAGS) docIndex.cpp
	
indexer.o: indexer.cpp
	$(CC) $(CFLAGS) indexer.cpp
	
fIndex.o: fIndex.cpp
	$(CC) $(CFLAGS) fIndex.cpp
	
URLResolver.o: URLResolver.cpp
	$(CC) $(CFLAGS) URLResolver.cpp

pageRank.o: pageRank.cpp
	$(CC) $(CFLAGS) pageRank.cpp

iIndex.o: iIndex.cpp
	$(CC) $(CFLAGS) iIndex.cpp

tokenizer.o: tokenizer.cpp
	$(CC) $(CFLAGS) tokenizer.cpp

stopwords.o: stopwords.cpp
	$(CC) $(CFLAGS) stopwords.cpp

clean: 
	rm -rf *o indexer
