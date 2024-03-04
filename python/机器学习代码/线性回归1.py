# -- coding:utf-8 --
from __future__ import print_function
import numpy as np
from matplotlib import pyplot as plt
from matplotlib.font_manager import FontProperties
font=FontProperties(fname=r'c:\Windows\Fonts\simsun.ttc',size=14)   # 解决windows环境下画图汉字乱码问题


def featureNormalize(x):  #对数据进行归一化处理
    X_norm=np.array(x)  #将数据转化成np数组对象，才可以进行矩阵运算

    #定义所需要的变量
    mu=np.zeros((1,x.shape[1]))
    sigma=np.zeros((1,x.shape[1]))

    mu=np.mean(X_norm,0)  #求每一列的平均值（0指定列，1指定行）
    sigma=np.std(X_norm,0) #求每一列的标准差

    for i in range(x.shape[1]):  #遍历列
        X_norm[:,i]=(X_norm[:,i]/mu[i])/sigma[i] #归一化

    return X_norm,mu,sigma


def cost(x,y,theta):  #代价函数
    m=len(y)
    J=0
    J=(np.transpose(x*theta-y))*(x*theta-y)/(2*m)  #计算代价
    return J


def gradientDescent(x,y,theta,alpha,num_iters): #梯度下降算法
    m=len(y)
    n=len(theta)
    temp=np.matrix(np.zeros((n,num_iters)))   #暂存每次迭代计算的theta，并将其转化成矩阵

    J_history=np.zeros((num_iters,1))  #记录每次迭代的代价值

    for i in range(num_iters):  #多次迭代
        h=np.dot(x,theta)  #矩阵乘法
        temp[:,i]=theta-((alpha/m))*(np.dot(np.transpose(x),h-y))
        theta=temp[:,i]
        J_history[i]=cost(x,y,theta)

    return  theta,J_history

def plotJ(J_history,num_iters):  #画出每次迭代代价的变化图
    x=np.arange(1,num_iters+1)
    plt.plot(x,J_history)
    plt.rcParams['font.sans-serif'] ='STHupo'
    plt.xlabel(u'迭代次数')  #必须指定字体，不然会乱码fontprooerties=font
    plt.ylabel(u'代价值')
    plt.title(u'代价值随迭代次数的变化')
    plt.show()


def drawLine(x,y):
    plt.plot(x,y,'o')
    plt.rcParams['font.sans-serif'] = 'STHupo'
    plt.xlabel(u'自变量')  # 必须指定字体，不然会乱码fontprooerties=font
    plt.ylabel(u'因变量')
    plt.title(u'散点图')
    plt.show()
def linearRegression(alpha=0.01,num_iters=400): #学习率和迭代次数
    print('数据加载中....')

    data = [
        [0.067732, 3.176513], [0.427810, 3.816464], [0.995731, 4.550095], [0.738336, 4.256571], [0.981083, 4.560815],
        [0.526171, 3.929515], [0.378887, 3.526170], [0.033859, 3.156393], [0.132791, 3.110301], [0.138306, 3.149813],
        [0.247809, 3.476346], [0.648270, 4.119688], [0.731209, 4.282233], [0.236833, 3.486582], [0.969788, 4.655492],
        [0.607492, 3.965162], [0.358622, 3.514900], [0.147846, 3.125947], [0.637820, 4.094115], [0.230372, 3.476039],
        [0.070237, 3.210610], [0.067154, 3.190612], [0.925577, 4.631504], [0.717733, 4.295890], [0.015371, 3.085028],
        [0.335070, 3.448080], [0.040486, 3.167440], [0.212575, 3.364266], [0.617218, 3.993482], [0.541196, 3.891471]
    ]
    data=np.array(data)
    X=data[:,0:1]  #x对应第0列到倒数第二列
    y=data[:,1]    #y对应最后一列
    m=len(y)
    col=data.shape[1]  #data的列数
    drawLine(X,y)
    x,mu,sigma=featureNormalize(X) #归一化
    x=np.hstack((np.ones((m,1)),x)) #再X前面加一列1

    print("-------执行梯度下降算法----------")
    theta=np.zeros((col,1))
    y=y.reshape(-1,1)  #将行向量转化成列向量
    theta,J_histroy=gradientDescent(x,y,theta,alpha,num_iters)
    drawLine(x,y)
    plotJ(J_histroy,num_iters)
    return mu,sigma,theta


def test():  #测试线性回归函数
    mu,sigma,theta=linearRegression(0.01,400)
    print("迭代后的参数值为",theta)
    print('数据的平均数为',mu)


if __name__ == '__main__':
    test()






