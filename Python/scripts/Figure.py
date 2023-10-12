import matplotlib.pyplot as plt


def makeFigure(xLimit, yLimit, title="Data"):
    xmin, xmax = xLimit
    ymin, ymax = yLimit
    fig = plt.figure()
    ax = plt.axes(xlim=(xmin, xmax), ylim=(int(ymin - (ymax - ymin) / 10), int(ymax + (ymax - ymin) / 10)))
    ax.set_title(title)
    ax.set_xlabel("Samples")
    ax.set_ylabel("Output")
    return fig, ax