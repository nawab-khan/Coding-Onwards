class ProductOfNumbers {
public:

    vector<int> vec;

    ProductOfNumbers() {

    }
    
    void add(int num) {
        
        int n = vec.size();

        for(int i=0;i<n;i++)
            vec[i] *= num;
        
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        
        return vec[vec.size()-k];

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */