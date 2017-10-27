import numpy as np

"""
This strikes me as a lot easier than it looks. Unless I'm reading this wrong 
there's a linear algebra solution to this task. Though it should be noted it's
not particularly robust to noise. This also makes a really weak assumption that

Alternatively we could use the RANSAC algorithmn
"""


def leastsquares_transform(initial, projection):

	"""
	This wasn't affine
	transform_matrix = np.dot(np.linalg.pinv(initial), projection)
	"""

	# assuming that the matricies are 2xN or 3xN
	rows, columns = projection.shape

	print rows, columns

	one_vec =  np.ones((1,columns))
	print one_vec.shape
	Q = np.vstack((projection, one_vec))

	P = np.vstack((initial, one_vec))
	print np.dot(P,P.T)
	P_inv = np.linalg.inv(np.dot(P,P.T))

	affine_transform = np.dot(Q,P.T).dot(P_inv)

	return affine_transform



def affine_transform(initial, projection):
	"""
	for the sake of simplicity I'm assuming that we're given arrays whose
	dimensions match.

	this was going to be an implementation of the RANSAC Algorithmn but that
	is a bit beyond the scope of this task
	"""

	if initial.shape[1]  == 2 :
		transform_matrix = np.zeros((3,3))


	elif inital.shape[1] == 3:
		transform_matrix = np.zeros((4,4))

	sample_size = 3
	count = 0
	limit = 25


	"""
	RANSAC ALGORITHM
	"""


	return transform_matrix


A = np.array([[2,1,2],[2,2,4]])

B = np.array([[3,3,2],[3,1,2]])

print leastsquares_transform(A,B)