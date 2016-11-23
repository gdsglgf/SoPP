import os
import sys
version = sys.version_info[0]
if version == 3:	# python 3
	from functools import reduce

def concat(x, y):
	return x + y

def word_id(word):
	''' rearrange the word with lower letters in order '''
	word = word.lower()
	letters = [i for i in word]
	letters.sort()
	# result = ''
	# for i in letters:
	# 	result = result + i

	return reduce(concat, letters)


def find_anagram(filename, nums=3):
	''' find all the words in a file with more than nums anagrams
		eg: 'silent' is an anagram of 'listen'
	'''
	print('------------%s' %(filename))
	word_dict = {}
	with open(filename) as f:
		for line in f:
			word = line.rstrip()
			word_sorted = word_id(word)
			word_list = word_dict.get(word_sorted, [])
			word_list.append(word)
			word_dict[word_sorted] = word_list

	for key, value in sorted(word_dict.items(), key=lambda d: d[0]):
		if len(value) >= nums:
			print('%s : %s' %(key, value))


def remove_dup(filename):
	''' remove duplicate words in file and sort the result'''
	words = set()
	with open(filename) as f:
		for line in f:
			line = line.rstrip()
			if line in words:
				print(line)		# 
			else:
				words.add(line)

	for w in sorted(words, key=str.lower):
		print(w)


def cmp_file(f1, f2):
	''' compare two files: 
	find the first difference place and show it'''
	with open(f1) as a, open(f2) as b:
		i = 0
		for line1, line2 in zip(a, b):
			i += 1
			if line1 != line2:
				print('%d %s -> %s' %(i, line1.rstrip(), line2.rstrip()))
				break


def test_word_id():
	word = 'applepie'
	print('%s -> %s' %(word, word_id(word)))


def test_sorted():
	print('sort list:')
	words = ['hello', 'kitty', 'cat']
	print(words)
	print(sorted(words, key=str.lower))

	print('sort set:')
	print(words)
	words = set(words)
	print(words)
	print(sorted(words, key=str.lower))


def test_version():
	print(sys.version_info)
	v = sys.version_info[0]
	print(v, type(v))
	print(sys.version)

if __name__ == '__main__':
	test_word_id()
	test_sorted()
	test_version()

	# print(sys.argv)
	filename = 'cet4-words.txt'
	if len(sys.argv) == 2:
		filename = sys.argv[1]

	if os.path.isfile(filename):
		find_anagram(filename)
	else:
		print('File not found: %s!\nUsage: python anagram.py file' %(filename))