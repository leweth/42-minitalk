# In this text, nothing is expected to be seen

../client $(ps | grep ./server | awk 'NR==1{print $1}') ""