import sys
from subprocess import call

file = open("test_config", "r") 
line1 = file.readline()
n_list = list(map(int, line1.strip().split("=")[1].split(",")))
line2 = file.readline()
dim_list = list(map(int, line2.strip().split("=")[1].split(",")))

for n in n_list:
	for dim in dim_list:
		output_filename = "dataset_" + str(n) + "_" + str(dim) + ".csv"

		call(["python", "generator.py",
			"-D", str(dim),
			"--num-clusters", "4",
			"--cluster-distance", "50",
			"--cluster-size", "20", "10", "10", "15",
			"--random-state", "0",
			"-o", output_filename,
			str(n)])

		print("Generated", output_filename)

		call(["mv", output_filename, "../datasets/" + output_filename])