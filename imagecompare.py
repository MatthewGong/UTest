import numpy as np
import os
from matplotlib import pyplot as plt



def compare(file1,file2):
	"""Load two image files and compare the difference between them"""

	# Load in the two image files
	img1 = plt.imread(file1)
	img2 = plt.imread(file2)

	print img1.shape

	# Compare the two images
	diff = img1 - img2


	# Create the figure and populate the subplots
	plt.figure()


	plt.subplot(221)
	plt.imshow(img1)

	plt.subplot(222)
	plt.imshow(img2)

	plt.subplot(223)
	plt.imshow(diff)

	# Display the images and their difference
	plt.show()


	# Calculate some distance metrics to quantify the difference in images
	total_dist = np.sum(diff, axis=(0,1))

	average_dist = np.average(diff, axis=(0,1))
	
	pixels_img1 = np.count_nonzero(img1)/3
	pixels_img2 = np.count_nonzero(img2)/3

	count_dist = pixels_img1 - pixels_img2

	print count_dist, total_dist, average_dist

	return {
		"count"   : count_dist,
		"average" : average_dist,
		"total"   : total_dist
	}



file1 = os.path.join("test_data", "diff_test", "test_image_1.png")
file2 = os.path.join("test_data", "diff_test", "test_image_2.png")

compare(file1,file2)