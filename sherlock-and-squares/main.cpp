#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

/*
Input
100
213 874
300 346
252 879
208 867
152 871
47 320
53 292
152 823
354 800
275 558
298 457
236 785
85 154
156 435
192 778
470 688
95 602
125 926
467 942
413 556
202 588
266 893
203 511
336 995
311 882
64 822
17 834
477 718
42 893
367 388
227 380
270 636
281 949
69 360
184 945
488 723
294 860
40 47
130 421
423 583
294 599
172 669
216 275
159 859
478 552
35 180
404 795
301 907
275 668
124 886
53 203
63 687
405 826
125 419
212 667
91 317
16 368
94 277
414 558
370 756
82 689
57 927
476 511
96 688
346 454
46 855
277 694
232 350
73 578
194 660
45 827
40 943
354 661
241 947
457 607
336 778
34 696
152 911
36 423
280 511
213 281
428 961
149 527
202 711
41 747
494 587
72 269
460 940
204 824
182 555
6 744
344 454
475 814
394 446
422 618
251 790
144 658
121 743
31 711
354 387
*/

/*
Output:
15
1
14
15
17
11
10
16
10
7
4
13
3
8
14
5
15
19
9
3
10
13
8
13
12
21
24
5
23
0
4
9
14
10
17
4
12
0
9
4
7
12
2
17
2
8
8
13
9
18
7
19
8
9
11
8
16
7
3
8
17
23
1
17
3
23
10
3
16
12
22
24
7
15
3
9
21
18
15
6
2
11
10
12
21
2
8
9
14
10
25
3
7
2
4
13
14
17
21
1
*/
ll sherlock_and_squares(ll a, ll b)
{
    ll ret = 0;
    ll start = (ll) sqrt(a);
    ll start_2 = pow(start, 2);
    while(start_2 <= b){
        if(!(start_2 < a))
            ret++;
        start_2 = start_2 + 2 * start + 1; // (n+1)^2 - (n)^2 = n^2 + 2*n + 1 - n^2
        start = start + 1;
    }
    return ret;
}

int main()
{
    int t;
    ll a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << sherlock_and_squares(a, b) << endl;
    }
    return 0;
}
