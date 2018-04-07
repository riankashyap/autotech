from PIL import Image
from pytesseract import image_to_string
import pyttsx
from gtts import gTTS
import os
import cv2

imgg = "image.jpg"
language = 'en'
ramp_frames = 30
camera_port = 1

camera = cv2.VideoCapture(camera_port)
def get_image():
	retval, im = camera.read()
	return im
for i in xrange(ramp_frames):
	temp = get_image()
print("Taking image...")
camera_capture = get_image()
file = imgg
cv2.imwrite(file, camera_capture)
del(camera)

a = image_to_string(Image.open(imgg))
print a

myobj = gTTS(text=a, lang=language, slow=False)
myobj.save("welcome.mp3")
os.system("mpg321 welcome.mp3")

# TO USE SYSTEM TTS ENGINE UNCOMMENT BELOW
#engine = pyttsx.init()
#engine.say(a)
#engine.runAndWait()

