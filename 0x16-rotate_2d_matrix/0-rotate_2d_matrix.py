def rotate_2d_matrix(matrix):
    """ Rotate 90° matrix"""
    temp = matrix.copy()
    matrix.clear()
    for y in range(len(temp[0])):
        t = []
        for x in reversed(range(len(temp))):
            t.append(temp[x][y])
        matrix.append(t)
