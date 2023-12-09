import sys
import os
from pytube import YouTube
from moviepy.editor import VideoFileClip


SAVE_PATH = "output/"

def error(msg):
    print(msg)
    sys.exit(1)

def getVideoFromArg():
    argLen = len(sys.argv)
    if argLen != 2:
        error("Error: Invalid Argument")
    print(sys.argv[1])
    return sys.argv[1]

try:
    videoLink = getVideoFromArg()
    yt = YouTube(videoLink)
    print(f"Downloading video: {yt.title} {videoLink}")


    videoTitle = yt.title
    yt.streams.get_highest_resolution().download(output_path=SAVE_PATH, filename=f"{videoTitle}.mp4")
    print("Download Successfully")

    inputVideo = SAVE_PATH + f"{videoTitle}.mp4"
    outputVideo = SAVE_PATH + f"{videoTitle}_cut.mp4"

    video = VideoFileClip(inputVideo)
    envDuration = os.environ.get("VIDEO_DURATION")
    videoDuration = envDuration if envDuration else video.duration
    cut_video = video.subclip(0, 10)
    cut_video.write_videofile(outputVideo, codec='libx264')

    print("Video kesildi ve kaydedildi.")
except Exception as e:
    print(e)
