#include<string>
#include<cmath>
#include<stack>
#include<iostream>
#include<cctype>

int priority(char op){
    switch(op)
    {
        case '*':
        case '/':
            return 2;

        case '-':
        case '+':
            return 1;

        default:
            return 0;
            break;
    }
}

double calculate(char op,std::stack<double>&nums){
    if(nums.empty()){
        std::cout<<"ILLEGAL"<<std::endl;
        std::exit(EXIT_FAILURE);
    }
    else{
    double b=nums.top();
    nums.pop();
    
    if(nums.empty()){
        std::cout<<"ILLEGAL"<<std::endl;
        std::exit(EXIT_FAILURE);
    }
    else{
        double a=nums.top();
        nums.pop();
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            //if(b==0){
            //    std::cout<<"ILLEGAL"<<std::endl;
            //    std::exit(EXIT_FAILURE);
            //}
            return a/b;

        default:
            return 0;

            break;          
             }
        }
    }
}

void evaluate_expression(const std::string& ss){

    std::string string1;
    if(ss.empty()) return;
    
    if(ss[0]=='+'||ss[0]=='/'||ss[0]=='*'||ss[0]==')'){
        std::cout<<"ILLEGAL"<<std::endl;
        return ;
    }
    for(int i=0;i<ss.length();i++){
        if((ss[i]=='+'||ss[i]=='-'||ss[i]=='*'||ss[i]=='/')&&(ss[i+1]=='+'||ss[i+1]=='-'||ss[i+1]=='*'||ss[i+1]=='/')){
        std::cout<<"ILLEGAL"<<std::endl;
        return ;
        }
        if((!isdigit(ss[i]))&&(ss[i]!='+')&&(ss[i]!='-')&&(ss[i]!='*')&&(ss[i]!='/')&&(ss[i]!='(')&&(ss[i]!=')')&&(ss[i]!='.')){
            std::cout<<"ILLEGAL"<<std::endl;
            return ;
        }
    }


        string1="";
        for(int i=0;i<ss.length();i++){
            if(ss[i]=='-'&&((i&&!isdigit(ss[i-1])||i==0))){
                string1+="0-";
            }else string1+=ss[i];
        }
        int i=0;
        std::stack<double> nums;
        std::stack<char> op;
        
        //统计左右括号次数
        int nl=0;
        int nr=0;
        while(i<string1.length()){
            std::string in1="";
            while(isdigit(string1[i])||string1[i]=='.'){
            in1 +=string1[i];
            i++;
            }
            if(in1!="")
            {double num = std::stod(in1);
             nums.push(num);
            }//处理符号
            if(!op.empty()){
                if(string1[i]=='+'||string1[i]=='-'||string1[i]=='*'||string1[i]=='/'){
                        if(priority(string1[i])<=priority(op.top())){
                            
                            if(op.top()=='/'){
                                if(nums.top()==0){
                                    std::cout<<"ILLEGAL"<<std::endl;
                                    return ;
                                }
                            }
                            double out1 = calculate(op.top(),nums);
                            nums.push(out1);
                            op.pop();
                        }
                        op.push(string1[i]);
                    }
                if(string1[i]=='('){
                    op.push(string1[i]);
                    nl++;
                    }
                if(string1[i]==')'){
                    nr++;
                    while(op.top()!='('&&(!nums.empty())){
                                                    if(op.top()=='/'){
                                if(nums.top()==0){
                                    std::cout<<"ILLEGAL"<<std::endl;
                                    return ;
                                }
                            }
                        double out1 = calculate(op.top(),nums);
                        nums.push(out1);
                        op.pop();
                    }
                    if(nums.empty())
                    {
                        std::cout<<"ILLEGAL"<<std::endl;
                        return ;
                    }
                    if(op.top()=='('){
                        op.pop();
                    }    
                    
                /*
                double out1=calculate(nums,op.top());
                nums.push(out1);
                op.pop();
               
                op.pop();/弹出（
                */
                }
            i++;
        }
        else if(string1[i]=='+'||string1[i]=='-'||string1[i]=='*'||string1[i]=='/'||string1[i]=='('){
                    op.push(string1[i]);
                    if(string1[i]=='(')
                    {
                        nl++;
                    }
                    i++;
                    
                }       
                
        }//整个计算式结束；
        if (nl!=nr)
        {
            std::cout<<"ILLEGAL"<<std::endl;
            return ;
        }
        
        while(!op.empty()){
                                        if(op.top()=='/'){
                                if(nums.top()==0){
                                    std::cout<<"ILLEGAL"<<std::endl;
                                    return ;
                                }
                            }
            double out1 = calculate(op.top(),nums);
            nums.push(out1);
            op.pop();
        }
        if(!nums.empty()){
        std::cout<<"result:"<<nums.top()<<std::endl;            
    }
        else{
             std::cout<<"ILLEGAL"<<std::endl;
            return ;
        }
}







