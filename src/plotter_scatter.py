import sys
import pandas as pd

import matplotlib.pyplot as plt

dataset = pd.read_csv(sys.argv[1], header=None)

x_min, x_max = dataset[0].min() - .5, dataset[0].max() + .5
y_min, y_max = dataset[1].min() - .5, dataset[1].max() + .5

plt.figure(2, figsize=(8, 6))
plt.clf()

plt.scatter(dataset[0], dataset[1], s=10, cmap=plt.cm.Paired)

#for i in range(len(dataset)):
#	plt.annotate(str(i), (dataset.loc[i,0], dataset.loc[i,1]))

plt.xlim(x_min, x_max)
plt.ylim(y_min, y_max)
plt.xticks(())
plt.yticks(())

plt.show()