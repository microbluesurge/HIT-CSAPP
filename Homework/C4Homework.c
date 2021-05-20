/*
4.45
A. 这段代码没有正确的表示pushq %rsp
因为最后的运行时栈值是%rsp减8之后的值
B. 应该改为
movq REG,-8(%rsp)
sub $8,%rsp
*/

/*
4.46
A. 这段代码没有正确的表示popq %rsp
因为将运行时栈的值存放到%rsp后还对%rsp进行了-8操作
B. 应该改为
addq $8,%rsp
movq -8(%rsp),REG
*/

/*
阶段                iaddq V,rB
取指                icode：ifun<-M1[PC]
                    rA:rB<-M1[PC+1]
                    valC<-M1[PC+2]
                    valP<-M1[PC+10]
译码                valB<-R[rB]
执行                valE<-valC+valB
访存
写回                R[rB]<-valE
更新PC              PC<-valP
*/