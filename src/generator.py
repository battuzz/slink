import sys
import numpy as np
import argparse


def build_parser():
	parser = argparse.ArgumentParser(description="Process generator parameters")
	parser.add_argument('N', help="Number of points to generate", type=int)
	parser.add_argument('-D', '--dim', '-d', help="Number of dimensions", default=2, type=int, required=False)
	parser.add_argument('--num-clusters', help="Number of clusters", default=2, type=int, required=False)
	parser.add_argument('--cluster-distance', help="Distance between clusters", type=float, required=False, default=1.0)
	parser.add_argument('--cluster-size', help="A series of N floats describing the size of each cluster", required=False, default=None, nargs='*', type=float)
	parser.add_argument('--random-state', help="Set the random state", default=-1, type=int)
	parser.add_argument('-o', '--output', help="Output file name", default="output.csv", required=False)

	return parser

def generate_dataset(N, dim, num_clusters, cluster_size, cluster_distance, random_state):
	points = []

	if random_state != -1:
		np.random.seed(random_state)

	cluster_centers = np.random.rand(num_clusters, dim) * cluster_distance
	for point in range(N):
		# Randomly choose a cluster
		cluster = np.random.randint(0, num_clusters)
		points.append(np.random.rand(dim) * cluster_size[cluster] + cluster_centers[cluster])

	return points

def write_output(data, filename):
	with open(filename, 'w') as f:
		for line in data:
			f.write(','.join(map(str,line)) + '\n')

def main():
	parser = build_parser()
	arguments = parser.parse_args()

	N = arguments.N
	dim = arguments.dim
	num_clusters = arguments.num_clusters
	cluster_size = arguments.cluster_size
	cluster_distance = arguments.cluster_distance
	random_state = arguments.random_state
	filename = arguments.output

	if cluster_size is None:
		cluster_size = [1.0] * num_clusters
	elif len(cluster_size) != num_clusters:
		parser.print_usage()
		sys.exit(0)

	data = generate_dataset(N, dim, num_clusters, cluster_size, cluster_distance, random_state)
	write_output(data, filename)



if __name__ == '__main__':
	main()