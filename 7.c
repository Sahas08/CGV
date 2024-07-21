import cv2
import numpy as np
import matplotlib.pyplot as plt
# Read the image
img = cv2.imread('/home/user/Desktop/MediaPipePoseEstimation/PgmTest/rabbit.jpeg')
# Get the height and width of the image
height, width = img.shape[:2]
# Split the image into four quadrants
quad1 = img[:height//2, :width//2]
quad2 = img[:height//2, width//2:]
quad3 = img[height//2:, :width//2]
quad4 = img[height//2:, width//2:]
plt.figure(figsize=(10, 10))
plt.subplot(2, 2, 1)
plt.imshow(quad1)
plt.title("1")
plt.axis("off")
plt.subplot(2, 2, 2)
plt.imshow(quad2)
plt.title("2")
plt.axis("off")
plt.subplot(2, 2, 3)
plt.imshow(quad3)
plt.title("3")
plt.axis("off")
plt.subplot(2, 2, 4)
plt.imshow(quad4)
plt.title("4")
plt.axis("off")
plt.show()
