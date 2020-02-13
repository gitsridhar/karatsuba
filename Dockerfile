ROM registry.access.redhat.com/ubi7:latest
LABEL name="Sridhar Karatsuba" \
      vendor="sridhar" \
      version="0.0.9" \
      release="1" \
      run='docker run karatsuba' \
      summary="An implementation of Karatsuba algorithm."\
      description="This includes an implementation of Karatsuba algorithm to multiply two numbers"\
      maintainers="Sridhar Venkat"
COPY karatsuba /karatsuba
RUN chmod +x /karatsuba
ENTRYPOINT ["/karatsuba"]
