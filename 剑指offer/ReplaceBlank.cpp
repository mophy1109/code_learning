// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str,int length) {//length为str总容量
        if (str == NULL || length == 0) return;
        
        int len,num = 0;
        while(str[len] != '\0'){//O(N)
            if(str[len] == ' '){
                num++;
            }
            len++;
        }

        int newlen = len + 2*num;
        str[newlen] = '\0';
        while(len >= 0 && newlen>len){
            if(str[len] != ' '){
                str[newlen--] = str[len];
            }else{
                str[newlen--] = '0';
                str[newlen--] = '2';
                str[newlen--] = '%';
            }
            len--;
        }
	}
};