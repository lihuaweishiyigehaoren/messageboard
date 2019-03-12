build/objs/Client.cpp.o :src/Client.cpp
	@mkdir -pv $(dir $@)
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) -o $@ $<

