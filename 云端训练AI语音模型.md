[羽毛整合包](https://www.yuque.com/umoubuton/ueupp5)

# **无扩散模型**

## 一.数据集的制作（UVR5)

-  分离伴奏：
   1. Process Method：Demucs
   2. Stem：Vocals
   3. Demucs Model：vs|UVR-Model-1
   4. 勾选GPU conversion

-  去除混响和和声（混响去不干净）：
   1. 输入上一步处理后的纯人声素材
   2. Process Method：VR Architecture
   3. Windows Size：320
   4. Aggression：10
   5. VR Model：5_HP_Karaoke_UVR
   6. 勾选GPU conversion

-  去除混响和回声 ：

  - 使用 UVR5 的去混响模型（以下三个任选其一）：
    - UVR-De-Echo-Normal选No Echo Only（轻度混响）
    - UVR-De-Echo-Aggressive选No Echo Only（重度混响）
    - UVR-De-Echo-Dereverb选No Echo Only（遇到鸟之诗这种变态的混响可以用）
  - 使用 UVR5 需要确保 UVR 版本在 5.6.0 以上，如果UVR里面没上述模型，点小扳手，去 Download Center 里面下载模型（请自备科学上网，否则会下载失败）

-  数据集切片：
  -  webUI小工具只能切片：输入存放wav的文件夹的路径

  -  设置3~15秒

  -  输出防在另一个文件夹

-  数据集制作完后存在阿里云盘

## 二.租用云端显卡

## 无扩散模型（up凉笙是咕咕咕）

- 网站：AutoDL

- 显卡要求：
  - 显存大于10
  - 酌情购买
  - 镜像选择：
    - 社区镜像：
      - 输入so-，找最后是Webull
      - innnky/so-vits-svc/so-vits-v4-Webull（可能略有改动）
  
- 开机后步骤;
  - 点击autopanel -> 公网网盘（第一次要设置密码） ->  阿里云盘 -> 下载数据集
  - 打开jupyterlab -> 点击三角逐步进行，直到提示“找不到目录”（此时镜像已经转移到数据盘，之前下载的数据也在数据盘）
  - 打开数据盘：auto-temp -> 把数据集剪切粘贴到镜像根目录中的dataset_raw
  - 再次打开readme文件 -> 三角执行，直到右上角变成空心圆代表执行完毕 -> 继续执行“自动划分数据集”（划分完后可以打开filelists文件夹验证：中间是训练集，另外两个是验证集和测试集，一般各有两条语音
  - 打开config文件修改一下参数（打开方式：editor）：修改keep_ckpts为10 -> Ctrl+s保存
  - 返回readme文件，继续执行生成hubert和f0文件 -> 0 -> 处理完后打开dataset文件夹检查一下（每一条语音后都有两个文件）
  - 装载预训练模型（第一次不需要）（第二次训练建议把整个盘删掉重新开始，所以也不需要）
  - 到镜像根目录（so-vits-svc.4)文件夹下打开终端 ->复制以下代码到终端执行
    - python train.py -c configs/config.json -m 44k
  - 训练一定步数以后，按Ctrl+c暂停，复制以下代码到根目录终端（这一步是在训练聚类模型）
    - python cluster/train_cluster.py
  - 若要继续训练：
    - 需要修改 configs/config.json这个配置文件中的epoch，再次执行 开始训练即可，程序会自动读取最新的模型
  - 下载本地推理要下的东西，都在logs/44k文件夹中
    - 配置文件：config.json
    - 模型文件：g开头的带步数的文件
    - 聚类模型：后缀为10000.pt
  
  ## 有扩散模型（up：徐昭空）
  
  - 网站：AutoDL
  
  - 显卡要求：
  
    - 显存大于12，最好拿24的显卡
    - 酌情购买
    - 镜像选择：
      - 社区镜像：
        - 输入svc，找：
        - svc-develop-team/so-vits-svc/so-vits-svc-4.1-Stable:v10
  
  - 开机后步骤;
  
    - 点击autopanel -> 公网网盘（第一次要设置密码） ->  阿里云盘 -> 下载数据集
    - 打开jupyterlab -> 点击三角第一步将数据转移到数据盘
    - 打开数据盘：auto-temp -> 把数据集移动到镜像根目录中的dataset_raw
    - 再次打开readme文件 -> 三角执行，直到右上角变成空心圆代表执行完毕 -> 
    - 打开config文件修改一下参数（打开方式：editor）：修改keep_ckpts为10 -> Ctrl+s保存
    - 返回readme文件，选编码器第一个，（数据集质量高可以选第二个）
    - 选f0预测器，第二个，复制参数，使用浅扩散模型
    - 继续执行，浅扩散模型放入
    - 到镜像根目录（so-vits-svc.4)文件夹下打开终端 ->复制以下代码到终端执行（训练浅扩散模型，10000步）
      - python train_diff.py -c configs/diffusion.yaml 
      - /logs/44k/diffusion
    - 到镜像根目录（so-vits-svc.4)文件夹下打开终端 ->复制以下代码到终端执行
      - python train.py -c configs/config.json -m 44k
    - 聚类模型
      - python cluster/train_cluster.py
    - 特征模型：
      - 生成的特征模型会保存在 logs/44k/feature_and_index.pkl
      - python train_index.py -c configs/config.json
  
    - 若要继续训练：
      - 需要修改 configs/config.json这个配置文件中的epoch，再次执行 开始训练即可，程序会自动读取最新的模型
    - 下载本地推理要下的东西，都在logs/44k文件夹中
      - 配置文件：config.json
      - 模型文件：g开头的带步数的文件
      - 聚类模型：后缀为10000.pt
  
    ## 