#define bck v[v.size()-1]
#define sz v.size()
int in_order(){
	int ret;
	node *t;
	
	if(sz == 0){
		t = root;
		while(t){
			v.pb(t);
			t = t->left;
			}
		}
	t = bck; v.pop_back();
	ret = t->info;
	if(t->right){
		t = t->right;
		while(t){
			v.pb(t);
			t = t->left;
			}
		}
	
	return ret;	
	}