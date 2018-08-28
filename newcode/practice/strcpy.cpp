char* strcpy(char* strDest, const char* strSrc){//输入参数声明为const，若拷贝构造中不使用const类型，将会调用拷贝构造函数生成形参，增加消耗；同时，不对输入参数进行修改，因此用const更合适,2分

    assert((strDest != NULL) && (strSrc != NULL));//边界条件，若表达式为false，终止执行，3分

    char* address = strDest; //记录首地址并在最后返回， 实现函数的链式调用，3分
    while((*strDest++ = *strSrc++) != '\0');//复制功能基础实现，2分

    return address;

}