FROM ubuntu as dynadjust-build
RUN mkdir -p /app/DynAdjust/
COPY . /app/DynAdjust/
WORKDIR /app
RUN apt-get update &&\
 apt-get install -y --no-install-recommends apt-utils &&\
 apt-get -y --no-install-recommends install sudo &&\
 DEBIAN_FRONTEND="noninteractive" &&\
 apt update &&\
 apt-get install -y tzdata &&\
 apt-get install -y wget &&\
 apt-get install -y python3 &&\
 apt-get install -y python3-pip &&\
 apt-get install -y --no-install-recommends gnupg2 &&\
 apt-get install -y --no-install-recommends p7zip &&\
 apt-get install -y --no-install-recommends libboost-system-dev libboost-filesystem-dev libboost-timer-dev libboost-thread-dev libboost-program-options-dev &&\
 apt-get install -y --no-install-recommends libxerces-c-dev &&\
 apt-get install -y --no-install-recommends cmake &&\
 apt-get install -y --no-install-recommends make &&\
 apt-get install -y --no-install-recommends g++ &&\
 apt-get install -y --no-install-recommends xsdcxx &&\
 wget https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS-2019.PUB && \
 apt-key add GPG-PUB-KEY-INTEL-SW-PRODUCTS-2019.PUB && \
 sh -c 'echo deb https://apt.repos.intel.com/mkl all main > /etc/apt/sources.list.d/intel-mkl.list' && \
 apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y install cpio intel-mkl-64bit-2018.3-051 &&\
 chmod +x ./DynAdjust/resources/make_dynadjust_gcc.sh &&\
 ./DynAdjust/resources/make_dynadjust_gcc.sh --no-install --auto --do-not-clone --test
WORKDIR /app/DynAdjust/dynadjust/
RUN coveralls --gcov /usr/bin/gcov --exclude-pattern ".*feature_tests.*" --exclude-pattern ".*CompilerId.*" --exclude-pattern ".*/resources/.*" --gcov-options '\-lp' >/dev/null 2>&1
RUN bash <(curl -s https://codecov.io/bash) >/dev/null 2>&1
  
