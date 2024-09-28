### Rebuild Of ErrorReport Project by VS.

---

# ErrorReport
A funny program to make fake error. Bad code, bad version manage, just for fun. :)

# Only support zh-cn

### 使用方法

运行 `ErrorReport.exe`。

#### 0. 配置文件

配置文件的第 $1$ 行应为报错类型。

目前可以使用的类型有：

MEMORY_ERROR。
DLL_MISSING_ERROR
EXE_ERROR

接下来的几行（必填），你应输入该报错类型所需的参数，程序会按顺序从配置文件中依次读取，失败的则程序崩溃。

每行表示一个参数，**记得要按顺序**。

#### 1. MEMORY_ERROR

该错误模拟的是“内存不能为 XXX”的弹窗，程序将会弹出：

> 标题：[ErrorProgram] - 应用程序错误
> 
> "[Operate]" 指令引用的 "[Address]" 内存。该内存不能为 "[CannotBe]"。
>  
> 要终止程序，请单击“确定”。  
> 要调试程序，请单击“取消”。

该功能的 4 个参数如下（按配置文件读取顺序排序）：

- ErrorProgram
- Operate
- Address
- CannotBe

配置文件示例：

```plain
MEMORY_ERROR
svchost.exe
0x00000000
0x00000000
read
```

#### 2. DLL_MISSING_ERROR

该错误模拟的是“DLL 文件缺失”的弹窗，程序将会弹出：

> 标题：[ErrorProgram] - 系统错误
> 
> 无法启动此程序，因为计算机中丢失 [MissingDll]。尝试重新安装该程序以解决此问题。

该功能的 2 个参数如下（按配置文件读取顺序排序）：

- ErrorProgram
- MissingDll

配置文件示例：

```plain
DLL_MISSING_ERROR
svchost.exe
coredpus.dll
```

#### 3. EXE_ERROR

该错误模拟的是“应用程序错误”的弹窗，程序将会弹出：

> 标题：[ErrorProgram] - 应用程序错误
> 
> 应用程序发生异常 [ErrorName] ([ErrorCode])，位置为 [Address]。
> 要终止程序，请单击“确定”。
> 要调试程序，请单击“取消”。

该功能的 4 个参数如下（按配置文件读取顺序排序）：

- ErrorProgram
- ErrorName
- ErrorCode
- Address

配置文件示例：

```plain
EXE_ERROR
svchost.exe
unknown software exception
0x00000000
0x0000000000000000
```
