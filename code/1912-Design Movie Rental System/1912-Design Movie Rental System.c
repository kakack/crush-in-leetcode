// You have a movie renting company consisting of n shops. You want to implement a renting system that supports searching for, booking, and returning movies. The system should also support generating a report of the currently rented movies.

// Each movie is given as a 2D integer array entries where entries[i] = [shopi, moviei, pricei] indicates that there is a copy of movie moviei at shop shopi with a rental price of pricei. Each shop carries at most one copy of a movie moviei.

// The system should support the following functions:

// Search: Finds the cheapest 5 shops that have an unrented copy of a given movie. The shops should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopi should appear first. If there are less than 5 matching shops, then all of them should be returned. If no shop has an unrented copy, then an empty list should be returned.
// Rent: Rents an unrented copy of a given movie from a given shop.
// Drop: Drops off a previously rented copy of a given movie at a given shop.
// Report: Returns the cheapest 5 rented movies (possibly of the same movie ID) as a 2D list res where res[j] = [shopj, moviej] describes that the jth cheapest rented movie moviej was rented from the shop shopj. The movies in res should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopj should appear first, and if there is still tie, the one with the smaller moviej should appear first. If there are fewer than 5 rented movies, then all of them should be returned. If no movies are currently being rented, then an empty list should be returned.
// Implement the MovieRentingSystem class:

// MovieRentingSystem(int n, int[][] entries) Initializes the MovieRentingSystem object with n shops and the movies in entries.
// List<Integer> search(int movie) Returns a list of shops that have an unrented copy of the given movie as described above.
// void rent(int shop, int movie) Rents the given movie from the given shop.
// void drop(int shop, int movie) Drops off a previously rented movie at the given shop.
// List<List<Integer>> report() Returns a list of cheapest rented movies as described above.
// Note: The test cases will be generated such that rent will only be called if the shop has an unrented copy of the movie, and drop will only be called if the shop had previously rented out the movie.

 

// Example 1:

// Input
// ["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
// [[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
// Output
// [null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]]

// Explanation
// MovieRentingSystem movieRentingSystem = new MovieRentingSystem(3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]);
// movieRentingSystem.search(1);  // return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. Shop 1 is cheapest; shop 0 and 2 are the same price, so order by shop number.
// movieRentingSystem.rent(0, 1); // Rent movie 1 from shop 0. Unrented movies at shop 0 are now [2,3].
// movieRentingSystem.rent(1, 2); // Rent movie 2 from shop 1. Unrented movies at shop 1 are now [1].
// movieRentingSystem.report();   // return [[0, 1], [1, 2]]. Movie 1 from shop 0 is cheapest, followed by movie 2 from shop 1.
// movieRentingSystem.drop(1, 2); // Drop off movie 2 at shop 1. Unrented movies at shop 1 are now [1,2].
// movieRentingSystem.search(2);  // return [0, 1]. Movies of ID 2 are unrented at shops 0 and 1. Shop 0 is cheapest, followed by shop 1.
 

// Constraints:

// 1 <= n <= 3 * 105
// 1 <= entries.length <= 105
// 0 <= shopi < n
// 1 <= moviei, pricei <= 104
// Each shop carries at most one copy of a movie moviei.
// At most 105 calls in total will be made to search, rent, drop and report.

#define MAX_ANS 5

typedef struct {
    int shop;
    int movie;
} MovieKey; //准备hash解的，先数组试试

typedef struct {
    MovieKey key;
    int price;
    bool isRent;
} Movies;

typedef struct {
    int movieNum;
    Movies *mvs; // 所有输入的列表，按mv和shop升序，参考cmpMvs
    Movies **srchList; // 用于Searh接口的排序表，参考cmpSrch
    Movies **rptList;  // 用于Report接口的排序表，参考cmpRpt
} MovieRentingSystem;

MovieRentingSystem g_sys = { 0 };

int cmpSrch(const void *a, const void *b)
{
    Movies **ma = (Movies **)a;
    Movies **mb = (Movies **)b;

    if (ma[0]->key.movie != mb[0]->key.movie)
        return ma[0]->key.movie - mb[0]->key.movie;
    if (ma[0]->price != mb[0]->price)
        return ma[0]->price - mb[0]->price;
    return ma[0]->key.shop - mb[0]->key.shop;
}

int cmpRpt(const void *a, const void *b)
{
    Movies **ma = (Movies **)a;
    Movies **mb = (Movies **)b;

    if (ma[0]->price != mb[0]->price)
        return ma[0]->price - mb[0]->price;           
    if (ma[0]->key.shop != mb[0]->key.shop)
        return ma[0]->key.shop - mb[0]->key.shop;
    return ma[0]->key.movie - mb[0]->key.movie;
}

int cmpMvs(const void *a, const void *b)
{
    Movies *ma = (Movies *)a;
    Movies *mb = (Movies *)b;

    if (ma->key.movie != mb->key.movie) {
        return ma->key.movie - mb->key.movie;
    }

    return ma->key.shop - mb->key.shop;
}

MovieRentingSystem *movieRentingSystemCreate(int n, int **entries, int entriesSize, int *entriesColSize)
{
    g_sys.movieNum = entriesSize;

    g_sys.mvs = (Movies *)malloc(entriesSize * sizeof(Movies));
    g_sys.srchList = (Movies **)malloc(entriesSize * sizeof(Movies *));
    g_sys.rptList = (Movies **)malloc(entriesSize * sizeof(Movies *));

    for (int i = 0; i < entriesSize; i++) {
        g_sys.mvs[i].isRent = false;
        g_sys.mvs[i].key.shop = entries[i][0];
        g_sys.mvs[i].key.movie = entries[i][1];
        g_sys.mvs[i].price = entries[i][2];

        g_sys.srchList[i] = &g_sys.mvs[i];
        g_sys.rptList[i] = &g_sys.mvs[i];        
    }

    qsort(g_sys.mvs, g_sys.movieNum, sizeof(Movies), cmpMvs);
    qsort(g_sys.srchList, g_sys.movieNum, sizeof(Movies *), cmpSrch);
    qsort(g_sys.rptList, g_sys.movieNum, sizeof(Movies *), cmpRpt);    

    return &g_sys;
}

// 是找到最左的边界
int BinSearch(MovieRentingSystem *obj, int movie)
{
    int mid;
    int min = 0;
    int max = obj->movieNum - 1;

    while(min <= max){
        mid = min + ( max - min ) / 2;
        if (obj->srchList[mid]->key.movie < movie) {
            min = mid + 1;
        } else if (obj->srchList[mid]->key.movie > movie){
            max = mid - 1;
        } else if(obj->srchList[mid]->key.movie == movie){
            max = mid - 1; // 继续找左边界
        }
    }

    if (min >= obj->movieNum || obj->srchList[min]->key.movie != movie) {
        return -1;
    }

    return min;
}

int *movieRentingSystemSearch(MovieRentingSystem *obj, int movie, int *retSize)
{
    int count = 0;
    int *ans = (int *)malloc(MAX_ANS * sizeof(int));

    int i = BinSearch(obj, movie);
    if (i == -1) {
        *retSize = 0;
        return NULL;
    }
    // 已经按要求排序
    for (; i < obj->movieNum; i++) {
        if (obj->srchList[i]->key.movie == movie && obj->srchList[i]->isRent == false) {
            ans[count++] = obj->srchList[i]->key.shop;
        }
        if (count >= MAX_ANS || obj->srchList[i]->key.movie > movie) {
            break;
        }
    }

    *retSize = count;
    return ans;
}


void setMovies(MovieRentingSystem *obj, int shop, int movie, bool isRent) {
    Movies want = {0};
    want.key.shop = shop;
    want.key.movie = movie;

    Movies *find = bsearch(&want, obj->mvs, obj->movieNum, sizeof(Movies), cmpMvs);

    find->isRent = isRent;
}

void movieRentingSystemRent(MovieRentingSystem *obj, int shop, int movie)
{
    setMovies(obj, shop, movie, true);
}

void movieRentingSystemDrop(MovieRentingSystem *obj, int shop, int movie)
{
    setMovies(obj, shop, movie, false);
}

int **movieRentingSystemReport(MovieRentingSystem *obj, int *retSize, int **retColSize)
{
    int count = 0;
    int **ans = (int **)malloc(MAX_ANS * sizeof(int *));
    // 已经按要求排序
    for (int i = 0; i < obj->movieNum; i++) {
        if (obj->rptList[i]->isRent == true) {
            ans[count] = (int *)malloc(2 * sizeof(int));
            ans[count][0] = obj->rptList[i]->key.shop;
            ans[count][1] = obj->rptList[i]->key.movie;
            count++;
        }
        if (count >= MAX_ANS) {
            break;
        }
    }

    *retSize = count;
    *retColSize = (int *)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        (*retColSize)[i] = 2;
    }

    return ans;
}

void movieRentingSystemFree(MovieRentingSystem *obj) {
    free(obj->mvs);
    free(obj->rptList);
    free(obj->srchList);
}
