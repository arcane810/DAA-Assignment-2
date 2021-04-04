import matplotlib.pyplot as plt
import sys

ifile = sys.argv[1]
ofile = ifile + ".out"

with open(ifile) as f:
    n, penalty = f.readline().split()
    n = int(n)
    x = []
    y = []
    for i in range(n):
        x1, y1 = map(float, f.readline().split())
        x.append(x1)
        y.append(y1)
    plt.scatter(x, y, color="black")
    # plt.savefig(ifile + ".rects.png")

with open(ofile) as f:
    error = f.readline()
    s = "Error: " + error
    plt.suptitle(s)
    n = int(f.readline())
    for i in range(n):
        a, b, c, d = map(float, f.readline().split())
        x = []
        y = []
        x.append(c)
        y.append(c * a + b)
        x.append(d)
        y.append(d * a + b)
        plt.plot(x, y)
    # plt.savefig(ifile + ".contours.png")
plt.show()