from pydub import AudioSegment
import argparse
import subprocess
import os

class VideoConversion(object):

	def __init__(self,inputFname,outputFname,timeInterval,volume):
		self.inputFname=inputFname
		self.outputFname=outputFname
		self.timeInterval=timeInterval
		self.volume=volume
		pass


	def create_audio_ffmpeg(self):
		command = "ffmpeg -i "+self.inputFname+" -af 'volume="+self.volume+"' -ab 160k -ac 2 -ar 44100 -vn "+self.outputFname
		subprocess.call(command, shell=True)
		if self.timeInterval:
			sound = AudioSegment.from_file(self.outputFname)
			outputFdetails=self.outputFname.split(".")
			j=1
			for time in self.timeInterval:
				start=self.time_to_msec(str(time[0]))
				print(start)
				end = self.time_to_msec(str(time[1]))
				print(end)
				output_sound = sound[start:end]
				file_name = outputFdetails[0]+str(j)+"."+outputFdetails[1]
				output_sound.export(file_name,format=outputFdetails[1])
				j+=1
			os.remove(self.outputFname)


	def time_to_msec(self,time):
		a=[]
		a=time.split(":")
		x=len(a)
		millisec=0
		if x:
			millisec += int(a[x-1])*1000
			x-=1
		if x:
			millisec += int(a[x-1])*60*1000
			x-=1
		if x:
			millisec += int(a[x-1])*3600*1000

		return millisec


class ArgHandling(object):
	pass