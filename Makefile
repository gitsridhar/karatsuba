
CXXFLAGS = -std=c++11 -lstdc++

REPO_NAME=svenkatdock
IMAGE_VERSION=2.0.2
IMAGE_NAME=$(NAME)
IMAGE_NAME = karatsuba
NAME = karatsuba
ALL = karatsuba

all: $(NAME)

docker-login:
ifndef $(and DOCKER_USERNAME, DOCKER_PASSWORD)
        $(error DOCKER_USERNAME and DOCKER_PASSWORD must be defined, required for goal (docker-login))
endif
	@docker login -u $(DOCKER_USERNAME) -p $(DOCKER_PASSWORD) $(DOCKER_SERVER)

final.o : cplusplus/final.cpp
	g++ -c $(CXXFLAGS) cplusplus/final.cpp

karatsuba: final.o
	g++ $(CXXFLAGS) -o $@ final.o

build-image: karatsuba
	docker build --network=host -t $(REPO_NAME)/$(IMAGE_NAME):$(IMAGE_VERSION) ./src

save-image: build-image
	docker save $(REPO_NAME)/$(IMAGE_NAME):$(IMAGE_VERSION) -o _output/$(IMAGE_NAME)_$(IMAGE_VERSION).tar

push-image: save-image
	docker push $(REPO_NAME)/$(IMAGE_NAME):$(IMAGE_VERSION)

clean:
	$(RM) $(ALL) *.o
