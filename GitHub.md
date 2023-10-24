## 一.上传代码（初学）

1. 初始化（若未出现.git文件，可以通过“查看->隐藏的项目”显示）

> git init

2. 关联本地仓库与GitHub仓库

   > git remote add origin git@github.com:用户名/仓库名.git
   >
   > 例：git remote add origin git@github.com:zzx051900/C-.git

3. 同步仓库到本地

> git pull git@github.com:用户名/仓库名.git
>
> git pull git@github.com:zzx051900/C-.git

4. 将要上传的文件添加到本地仓库

> git add .  (.表示提交所有文件)
>
> git commit -m "注释信息"   
>
> git push git@github.com:用户名/仓库名.git
>
> git push git@github.com:zzx051900/C-.git

## 二.修改文件（初学，理解很浅）

1. 之间覆盖仓库内文件
2. 执行一.4步骤

