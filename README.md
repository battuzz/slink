# SLINK implementation for Single Linkage Clustering

This project is an implementation of the SLINK algorithm developed by Sibson in 1973 and can be found [here][8bdaa30d].

  [8bdaa30d]: http://www.cs.gsu.edu/~wkim/index_files/papers/sibson.pdf "sibson paper SLINK"

SLINK is an optimally efficient algorithm for [single linkage clustering][1d8e13fd] that runs in O(N^2) time and O(N) space complexity.

  [1d8e13fd]: https://en.wikipedia.org/wiki/Single-linkage_clustering "single linkage"

We compared the result with a naive implementation of the same algorithm that runs in O(N^3) time and O(N^2) space and we also tried to optimize the naive implementation using segment trees to achieve O(N^2 log N) time complexity.

Further informations can be found in the `doc` folder.

## Compile and run the executables
To compile the program just type `make`.

This will produce a bunch of executables:
- `./bin/run_single_linkage` will run the naive version of the algorithm
- `./bin/run_single_linkage_optimized` will run the optimized naive implementation
- `./bin/run_slink` will run the SLINK algorithm

All these executables expect 2 input parameters: the input file and the output file. The input file is a `.csv` file and can be generated with the script `generator.py`.

## List of scripts:
- `generator.py` will output a csv file with the coordinate of points in space.
- `generate_dataset.py` will generate the dataset we used for benchmark
- `plotter_dendro.py` will plot the dendrogram from the linkage matrix (output of the single linkage program)
- `plotter_scatter.py` will plot the points in 2D space (to use only on bidimensional input)
- `run_tests.py` will run all the tests and collect the results.
