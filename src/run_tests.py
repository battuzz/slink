import sys
from subprocess import call

file = open("test_config", "r") 
line1 = file.readline()
n_list = list(map(int, line1.split('\n')[0].split("=")[1].split(",")))
line2 = file.readline()
dim_list = list(map(int, line2.split('\n')[0].split("=")[1].split(",")))

for n in n_list:
	for dim in dim_list:
		input_filename = "dataset_" + str(n) + "_" + str(dim) + ".csv"
		output_filename = "dataset_" + str(n) + "_" + str(dim) + "_results.csv"

		call(["../bin/run_single_linkage", "../datasets/" + input_filename, "../results/" + output_filename])
		call(["../bin/run_slink", "../datasets/" + input_filename, "../results/" + output_filename])