import matplotlib.pyplot as plt
import sys

ifile = sys.argv[1]
ofile = ifile + ".out"
mnx = 1e100
mxx = -1e100

with open(ifile) as f:
    n = int(f.readline())
    x = []
    y = []
    for i in range(n):
        x1, y1 = map(float, f.readline().split())
        x.append(x1)
        y.append(y1)
        mnx = min(x1, mnx)
        mxx = max(x1, mxx)
    plt.scatter(x, y, color="black")
    # plt.savefig(ifile + ".rects.png")

with open(ofile) as f:
    error = f.readline()
    s = "Error: " + error
    plt.suptitle(s)
    n = int(f.readline())
    for i in range(n):
        a, b = map(float, f.readline().split())
        x = []
        y = []
        x.append(mnx - 1)
        y.append((mnx - 1) * a + b)
        x.append(mxx + 1)
        y.append((mxx + 1) * a + b)
        plt.plot(x, y)
    # plt.savefig(ifile + ".contours.png")
plt.show()