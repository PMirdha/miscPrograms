from pydub import AudioSegment
import argparse
import subprocess
import os
from ClassConvert import VideoConversion

parser = argparse.ArgumentParser(description='Get all arguments')

# Example - python convert_video.py BokunoHeroAcademia3rdSeasonEpisode9.mp4 Hero_academia.mp3 --cut 00:20 1:50 -v 1.5

help = "Name of input file to be converted"
parser.add_argument('input_file_name',help=help)

help = "Name of output file"
parser.add_argument('output_file_name',nargs='?',help=help,default="output.mp3")

help = "cut audio in segments"
parser.add_argument('--cut',nargs='*',help=help)

help = "Volume in terms of decimal - 2.0, 1.5, 0.5"
parser.add_argument('-v',nargs='*',help=help)

args=parser.parse_args()

print("\n\n"+str(args)+"\n\n")
timeInterval=[]
if args.cut:
	if len(args.cut)%2!=0:
		parser.error("all start points should have an end point")
	for i in range(1,len(args.cut)):
		temp_list=list()
		temp_list.append(args.cut[i-1])
		temp_list.append(args.cut[i])
		timeInterval.append(temp_list)
		i+=1

if args.v:
	volume = args.v[0]
else:
	volume = '1.0'
print("\n\n"+str(timeInterval)+"\n\n")
print("\nVol - \n"+str(volume)+"\n\n")
vcObj=VideoConversion(args.input_file_name,args.output_file_name,timeInterval,volume)
vcObj.create_audio_ffmpeg()
exit()