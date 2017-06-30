import sys
import pandas as pd

from scipy.cluster import hierarchy
import matplotlib.pyplot as plt

linkageMatrix = pd.read_csv(sys.argv[1]);
linkageMatrix[linkageMatrix.columns] = linkageMatrix[linkageMatrix.columns].astype(float)

plt.figure(figsize=(10, 7))
dn = hierarchy.dendrogram(linkageMatrix.values)
hierarchy.set_link_color_palette(['m', 'c', 'y', 'k'])
plt.show()