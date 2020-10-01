#!/usr/bin/python

import subprocess

class ping_server(object):
	def __init__(self, ip, host):
		self.ip = ip
		self.host = host

	def ping(self):
		print "pinging %s from %s" % (self.ip, self.host)
		subprocess.call(["ping", self.ip])

if __name__ == '__main__':
	server=ping_server("192.168.1.1", "sini_pc")
	server.ping()

