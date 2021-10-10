# phonon-exercise

Program for practice in the lecture "Crystal and Phonon(結晶とフォノン)".

---

このリポジトリ内のプログラムは結晶とフォノンの演習問題用に作成しました．

## ex1

<img src="https://latex.codecogs.com/gif.latex?K=0,&space;\pi/3a,&space;\pi/2a,&space;\pi/a"/>\
の4つの場合について原子の振動パターンを示します．振動パターンが\
<img src="https://latex.codecogs.com/gif.latex?u_s=u\exp\left[i(sKa-\omega&space;t)\right]"/>\
で表されることを踏まえ，uやaを1として1周期を24分割した各時刻での平衡位置からの原子のズレを13個の原子についてCSV形式で`ex1ans.dat`に出力します．レポートのうちコマ撮りしている部分は`report.pdf`として掲載してあります．


## ex2

NaCl型結晶について（質量比17:11）、分散曲線、及び\
<img src="https://latex.codecogs.com/gif.latex?K=0,&space;\pi/4a,&space;\pi/2a,&space;\3\pi/4a,&space;\pi/a"/>\
の時のTO(横波音響)モード・TA(横波光学)モードの原子の変位パターンを計算します．a=2の設定下で分散曲線はKを0.01刻みで表し`ex2rel.dat`に、また今回は振動数が波数に依存するためコマ撮り間隔を一定としてCSV形式で`ex2ans.dat`に出力します．間隔が違うことも踏まえ今回はGIFによる表示も行いました．