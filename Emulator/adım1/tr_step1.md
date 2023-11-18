# MSKN Yükleme Aşamaları

Merhabalar, MSKN ile Komut Kolaylaştırıcı senaryomuza hoşgeldiniz. Bugün Pardus işletim sistemimizde terminalde kullandığımız komutları kolaylaştırmak için ortaya çıkarılmış bir program olan MSKN programını inceleyeceğiz.

### 1. Projeyi Kendi Ortamınıza Çekin

Öncelikle "git clone" komutu ile token kullanarak projeyi kendi ortamınıza klonlayın:

```sh
git clone https://<username>:<git_user_token>@github.com/MertGursimsir/mskn.git
```

Daha sonrasında proje dizinine gidin:

```sh
cd mskn
```

### 2. Gereksinimleri Yükleyin

Projede C kodunu compile etmek için "gcc" (GNU Compiler Collection) kullanılacaktır. Bu yüzden aşağıdaki komut ile "gcc" compilerını sisteminize yükleyin:

```sh
sudo apt-get install gcc
```

### 3. Kodu Compile Edin ve Çalıştırın

Compilation işlemi için aşağıdaki komutu kullanın:

```sh
gcc history.c -o history
```

Sonrasında aşağıdaki komut ile compile edilmiş dosyayı çalıştırın:

```sh
./history
```

### 4. Ek Yüklemeler

Eğer compilation hatası alırsanız aşağıdaki komutları uygulayıp 3. adıma geri dönün:

```sh
sudo apt-get update
sudo apt-get install build-essential
```

Eğer yine sonuç alamazsanız aşağıdaki komutu girin:

```sh
sudo apt-get install libc6-dev
```