import hashlib

def md5_hash(data):
    md5 = hashlib.md5()
    md5.update(data)
    return md5.digest()

if __name__ == "__main__":
    input_data = b"Hello, MD5!"
    hash_result = md5_hash(input_data)

    print("Input: {}".format(input_data.decode('utf-8')))
    print("MD5 Hash: {}".format(hash_result.hex()))
