中间件技术 COM 实验示例代码
=======================

### 运行环境

* Windows 7/8 
* Visual Studio 2013 Express for Windows Desktop / Community


### 代码说明

仓库中包含了多个 COM 实现：

* [纯 C++ 版](https://github.com/HIT-Alibaba/COM-Example/tree/master/Plain-C%2B%2B)
    
    代码来自 [Step by Step COM Tutorial](http://www.codeguru.com/cpp/com-tech/activex/tutorials/article.php/c5567/Step-by-Step-COM-Tutorial.htm)，略作修改使其能在 VS 2013 上编译。
    
* [使用第三方库](https://github.com/HIT-Alibaba/COM-Example/tree/master/Use-Third-Party-Lib)

	使用 [xlLib](https://github.com/Streamlet/xlLib) 库的实现
	
### 注意事项

* 注册 DLL 需要以管理员模式运行 cmd，然后再执行 regsvr32， 不然不能正确注册，切记！

    

