class String {
    int size;
    char* data;
public:
    String(int = 0);
    String(const char[]);
    String(const String&);
    friend String operator+(const String&, const String&);
    String& operator=(const String&);
    friend ostream& operator<<(ostream&, const String&);
    int operator==(const String&);
    String operator()(int, int);
    String& Rev();
    char& operator[](int index);
    int length();
    ~String();
};
String :: String(int s) {
    cout<<"Constructor called"<<endl;
    this->size = s + 1;
    this->data = new char[this->size];
    for(int i = 0; i < this->size - 1; i++)
        this->data[i] = ' ';
    this->data[this->size - 1] = '\0';
}
String :: String(const char* charr) {
    cout<<"Copy Constructor for char* called"<<endl;
    int length = 0;
    for( ; charr[length] != '\0'; length++);
    this->size = length+1;
    this->data = new char[this->size];
    for(int i = 0; i < this->size; i++)
        this->data[i] = charr[i];
}
String :: String(const String& str) {
    cout<<"Copy Constructor for String& called"<<endl;
    this->size = str.size;
    this->data = new char[this->size];
    for(int i = 0; i < str.size; i++)
        this->data[i] = str.data[i];
    this->data[this->size-1] = '\0';
}
String operator+(const String& s1, const String& s2) {
    cout<<"Operator + overload"<<endl;
    String tmp(s1.size + s2.size - 2);
    for(int i = 0; i < s1.size-1; i++)
        tmp.data[i] = s1.data[i];
    for(int j = 0; j < s2.size; j++)
        tmp.data[s1.size - 1 + j] = s2.data[j];
    return tmp;
}
String& String :: operator=(const String& str) {
    cout<<"Operator = overload"<<endl;
    if(this->data != NULL)
        delete []this->data;
    this->size = str.size;
    this->data = new char[this->size];
    for(int i = 0; i < str.size; i++)
        this->data[i] = str.data[i];
    return *this;
}
ostream& operator<<(ostream& os, const String& str) {
    os<<"Operator << overload"<<endl;
    for(int i = 0; i < str.size-1; i++)
        os<<str.data[i];
    return os;
}
int String :: operator==(const String& str) {
    cout<<"Operator == overload"<<endl;
    if(this->size != str.size)
        return 0;
    int flag = 1;
    for(int i = 0; i < this->size-1; i++)
        if(this->data[i] != str.data[i]) {
            flag = 0;
            break;
        }
    return flag;
}
String String :: operator()(int s, int cnt) {
    cout<<"Operator () overload"<<endl;
    int finalSize = 0;
    if(s >= this->size-1)
        finalSize = 0;
    else if(s + cnt <= this->size-2)
        finalSize = cnt;
    else if(s + cnt > this->size-2)
        finalSize = this->size - s - 1;
    String tmp(finalSize);
    for(int i = 0; i < finalSize; i++) {
        tmp.data[i] = this->data[s + i];
    }
    tmp[finalSize] = '\0';
    return tmp;
}
String& String :: Rev() {
    cout<<"Rev() called"<<endl;
    int length = this->size - 2;
    for(int i = 0; i <= length/2; i++) {
        char tmp = this->data[i];
        this->data[i] = this->data[length-i];
        this->data[length-i] = tmp;
    }
    return *this;
}
char& String :: operator[](int index) {
    cout<<"Operator [] overload"<<endl;
    return(this->data[index]);
}
int String :: length() {
    return (this->size - 1);
}
String :: ~String() {
    cout<<"Destructor called"<<endl;
}
