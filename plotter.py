import sys
import pandas as pd
import numpy as np

from scipy.cluster import hierarchy
import matplotlib.pyplot as plt

linkageMatrix = pd.read_csv(sys.argv[1]);
linkageMatrix[linkageMatrix.columns] = linkageMatrix[linkageMatrix.columns].astype(float)

plt.figure()
dn = hierarchy.dendrogram(linkageMatrix.values)
hierarchy.set_link_color_palette(['m', 'c', 'y', 'k'])
plt.show()