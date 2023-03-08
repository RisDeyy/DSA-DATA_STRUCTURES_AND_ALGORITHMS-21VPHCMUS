#include <bits/stdc++.h>

using namespace std;
#define MAX 100

void ReadFileG1_MatrixToList(char *filename1) {
	ifstream ifs(filename1);
	if (!ifs) 
	    cout << "File can't be opened!\n";

	int n;    
	int i = 0;
    int j = 0;

    ifs >> n;
    cout << n << endl;

    vector<vector<int> > adj(n);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int edge;
            ifs >> edge;
            
            if (edge == 1){
                adj[i].push_back(j);
            }
        }
	}

	ifs.close();

    for (i = 0; i < n; i++) {
        for (j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void ReadfileG2_ListToMatrix(){

    ifstream ifs("Graph2.txt");
	if (!ifs) 
	    cout << "File can't be opened!\n";

	int n;    
	int i = -1;
    int j = 0;
    string elm;

    ifs >> n;
    cout << n << endl;

    vector<vector<int> > adj(n, vector<int>(n, 0));

    while (getline(ifs, elm)){
        elm.push_back(n);
        //cout << endl;
        for (j = 0; j < elm.length(); j++) {
            if (elm[j] >= '0' && elm[j] <= '8') {
                adj[i][elm[j] - '0'] = 1;
            }else if(!elm[j]){
                adj[i][elm[j] - '0'] = 0;
            }
        }i++;
    }

     ifs.close();

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }cout << endl;
    }
}

bool IsUndirectedGraph(int n){
    vector<vector<int> > adj(n);
	bool *visited = new bool[adj.size()];
	visited[n] = true;
	for(int i = 0; i < adj.size(); i++){
		if(!visited[i]) return false;
	}
	return true;
	delete[] visited;
}

int CountEdge(int n){
	int count = 0;
    vector<vector<int> > adj(n);

	for(int i = 0; i < adj.size(); i++){
            count += adj[i].size();
    } 
	return count/2;
}

int CountVertices(int n){
    vector<vector<int> > adj(n);
    return adj.size();
}

vector<int> isolatedVertices(int n){
    bool flag;
    vector <int> sl_vect;
    vector<vector<int> > adj(n);
    for (int i = 0; i < adj.size(); i++){
        flag = 0;
        for (int j = 0; j < adj[i].size(); j++){
            if (adj[i][j]){
                flag = 1;
                break;
            }
        }
        if (!flag) 
            sl_vect.push_back(i);
    } return sl_vect;
}

bool isBigraph(int n){   //tham khao bai cua ban Vo Nam Dang lam tren bang
    vector<vector<int> >adj(n);
    queue <int> q;
    int u;
    int* color = new int [n] {};
    for (int s = 0; s < n; s++){
        if (color[s]){
            continue;
            q.push(s);
            color[s]= 1;
            while(!q.empty()){
                u = q.front();
                q.pop();
            }
        }
    }
    for(int v: adj[u]){
        if (!color[v]){
            q.push(v);
            color[v] = color[u] == 1?2:1;
        }else if(color[v] == color[u]){
            delete[] color;
            return 0;
        }
    }
}

void traverse(int u, bool visited[], int n){

    vector<vector<int> >adj(n);
	visited[u] = true;
	for(int v = 0; v < (signed) adj.size(); v++)
	{
		if(adj[u][v])
		{
			if(!visited[v]) 
            traverse(v, visited, n);
		}
	}
}

int CountConnectedComponents(int n){
	int count = 0;
	bool* visited = new bool[n];
	for(int v = 0; v < n; v++) visited[v] = false;
	for(int v = 0; v < n; v++)
	{
		if(visited[v] == false)
		{
			traverse(v, visited, n);
			count++;
		}
	}
	return count;
	delete[] visited;
}


int main (){

    char filename1[MAX] = {"Graph1.txt"};
    //char filename2[MAX] = {"Graph2.txt"};

    cout << "MATRIX TO LIST:\n\n";
    ReadFileG1_MatrixToList(filename1);

    cout << "\nLIST TO MATRIX:\n\n";
    ReadfileG2_ListToMatrix();

    int n;

    ifstream ifs(filename1);
    ifs >> n; 
    //cout << n;

    if(IsUndirectedGraph(n)) {
        cout << "\nThe graph is undirected\n";
    }
	else {
        cout << "\nThe graph is directed\n";
    }

    cout << "\nNumber of edges: " << CountEdge(n) << endl;
	cout << "\nNumber of vertices: " << CountVertices(n) << endl;

    if(isBigraph(n)){
        cout << "\nThe Graph is Bigraph\n";
    }
    else{
        cout << "\nThe Graph isn't Bigraph\n";
    }

    cout << "\nNumber of Connected components: " << CountConnectedComponents(n) << endl;

    system("pause");
    return 0;
}