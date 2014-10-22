#include<iostream>
#include<vector>
using namespace std;

struct Point{
	int x;
	int y;
	Point(int i, int j){
		x = i; 
		y = j;
	}
};

class solution_8_2 {

public:
	int getPathNum(vector<string> &grid, int N){
		vector<vector<int>> paths (N, vector<int> (N, 0));
		if(grid[0][0] == 'x') return 0;
		paths[0][0] = 1;
		for(int i = 1; i < N; i++) paths[i][0] = grid[i][0] == 'x' ? 0 : paths[i-1][0];
		for(int j = 1; j < N; j++) paths[0][j] = grid[0][j] == 'x' ? 0 : paths[0][j-1];

		for(int i = 1; i < N; i++){
			for(int j = 1; j < N; j++){
				if(grid[i][j] == 'x') continue;
				paths[i][j] += grid[i-1][j] == 'x' ? 0 : paths[i-1][j];
				paths[i][j] += grid[i][j-1] == 'x' ? 0 : paths[i][j-1];
			}
		}
		return paths[N-1][N-1];
	}

	// path ways:
	// math: choose (x-1) out of (x-1) + (y-1)
	
	// print paths, start from the dest
	void printAllPaths(vector<string> &grid, vector<Point*> &path, int x, int y){
		if(x == grid.size()-1 && y == grid[0].size()-1){
			for(int i = 0; i < path.size(); i++)
				cout << "(" << path[i]->x << "," << path[i]->y << ")" << endl;
			cout << endl;
			cout << endl;
		}

		// go down
		if(x + 1 < grid.size() && grid[x+1][y] == 'o'){
			Point *p = new Point(x+1,y);
			path.push_back(p);
			printAllPaths(grid, path, x+1, y);
			path.pop_back();
		}

		// go right
		if(y + 1 < grid[0].size() && grid[x][y+1] == 'o'){
			Point *p = new Point(x,y+1);
			path.push_back(p);
			printAllPaths(grid, path, x, y+1);
			path.pop_back();
		}
	}

};

int main(){
	solution_8_2 *obj = new solution_8_2();
	
	vector<string> v;
	/* x means obstacles */
	v.push_back("ooo");
	v.push_back("oxo");
	v.push_back("ooo");
	
	cout << obj->getPathNum(v, 3) << endl;

	vector<Point *> ps;
	ps.push_back(new Point(0,0));
	obj->printAllPaths(v, ps, 0, 0);
	return 0;
}