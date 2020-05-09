# WEEK 2:

1. Check if it is straight line: Usually we find slop using (y2-y2)/(x2-x1) and if the slope between every consecutive 2 points is same as the first 2 points , then we can say that the line is straight.
BUT this includes the possibility of division by 0 if 2 points are same , so rather than doing division , we can check using if((y2-y1)*(x3-x2)==(x2-x1)*(y3-y2)). If this condition satisfies every time then the line is straight.