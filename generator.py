import sys
import numpy as np

def usage():
	print("""Usage: {0} <ncluster> <dimensions> [cluster distance] [...clusters size...]
Examples: 
python {0} 5 2
   creates a dataset with 5 cluster in 2d.
python {0} 3 2 1 1 1
   creates a dataset with 3 clusters in 2d, each with a unitary sparsity
python {0} 3 4 2 5 5 5
   creates a dataset with 3 clusters in 4d. The 3 clusters have distance 2 and have a sparsity 5 each
""".format(sys.argv[0]))

def parse_args():
	if len(sys.argv < 3):
		usage()
		return False

	N = sys.argv[1]
	D = sys.argv[2]

	if len(sys.argv) > 2 + N:
		cluster_distance = sys.argv[3]
	else:
		cluster_distance = 1
	sparsities = sys.argv[-N:]

def main():
	if len(sys.argv) < 2:
		usage()
		return None

	N, D, cluster_distance, sparsities = parse_args()



if __name__ == '__main__':
	main()