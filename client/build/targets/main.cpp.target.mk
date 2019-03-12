build/objs/main.cpp.o :src/main.cpp src/Client.h
	@mkdir -pv $(dir $@)
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) -o $@ $<

