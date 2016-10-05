#!/usr/bin/python3

import os

def main():
	case1 = []
	case2 = []
	command = "./cachetest"

	m = 1000

	for i in range(26):
		n = 2 ** i
		command1 = command + "1.out --repetitions " + str(m)
		command1 += "--array_size" + str(n)
		case1 += [os.system(command1)]
		

