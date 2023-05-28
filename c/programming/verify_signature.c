#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int verify_pss_signature(const char* message, size_t message_len,
                         const char* signature, size_t signature_len,
                         const char* pubkey_file) {
    EVP_PKEY* pubkey = NULL;
    EVP_MD_CTX* md_ctx = NULL;
    int ret = 0;

    // Load the public key from file
    FILE* fp = fopen(pubkey_file, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open public key file\n");
        goto cleanup;
    }

    pubkey = PEM_read_PUBKEY(fp, NULL, NULL, NULL);
    fclose(fp);

    if (!pubkey) {
        fprintf(stderr, "Error: could not read public key\n");
        goto cleanup;
    }

    // Create and initialize the message digest context
    md_ctx = EVP_MD_CTX_new();
    if (!md_ctx) {
        fprintf(stderr, "Error: could not create message digest context\n");
        goto cleanup;
    }

    if (!EVP_DigestVerifyInit(md_ctx, NULL, EVP_sha256(), NULL, pubkey)) {
        fprintf(stderr, "Error: could not initialize message digest verification\n");
        goto cleanup;
    }

    // Set PSS padding
    EVP_PKEY_CTX* pkey_ctx = EVP_PKEY_CTX_new(pubkey, NULL);
    if (!pkey_ctx) {
        fprintf(stderr, "Error: could not create PKEY context\n");
        goto cleanup;
    }

    if (!EVP_PKEY_CTX_set_rsa_padding(pkey_ctx, RSA_PKCS1_PSS_PADDING)) {
        fprintf(stderr, "Error: could not set PSS padding\n");
        goto cleanup;
    }

    // Verify the signature
    if (!EVP_DigestVerifyUpdate(md_ctx, message, message_len)) {
        fprintf(stderr, "Error: could not update message digest verification\n");
        goto cleanup;
    }

    if (EVP_DigestVerifyFinal(md_ctx, (const unsigned char*)signature, signature_len) != 1) {
        fprintf(stderr, "Error: signature verification failed\n");
        goto cleanup;
    }

    printf("Signature verified successfully\n");
    ret = 1;

cleanup:
    if (md_ctx) {
        EVP_MD_CTX_free(md_ctx);
    }
    if (pubkey) {
        EVP_PKEY_free(pubkey);
    }
    if (pkey_ctx) {
        EVP_PKEY_CTX_free(pkey_ctx);
    }
    return ret;
}

int main() {
    const char* message = "Hello, world!";
    const char* signature = "<signature>"; // replace with actual signature
    const char* pubkey_file = "<pubkey.pem>"; // replace with actual public key file
    size_t message_len = strlen(message);
    size_t signature_len = strlen(signature);

    int ret = verify_pss_signature(message, message_len, signature, signature_len, pubkey_file);
    if (!ret) {
        fprintf(stderr, "Error: signature verification failed\n");
        return 1;
    }

    return 0;
}
