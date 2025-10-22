
        cycle.push_back(cycles);
        for(int v = cyclee; v != cycles; v = vis[v]){
            cycle.push_back(v);
        }
        cycle.push_back(cycles);
        cout << cycle.size() << endl;
        for(auto& v : cycle){
            cout << v << " ";
        }
        cout << endl;