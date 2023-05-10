myDir = File.dirname(File.expand_path(__FILE__));
require "#{myDir}/../build-options.rb";

module Rakish

cfg = BuildConfig("root");

depends=[
    "../artd-lib-logger",
    "#{cfg.thirdPartyPath}/oss-glm"
]

Rakish::CppProject.new(
	:name 			=> "artd-lib-vecmath",
	:package 		=> "artd",
	:dependsUpon 	=> depends
) do

	cppDefine('BUILDING_artd_lib_vecmath');

	addPublicIncludes('include/artd/*.h');

    addSourceFiles(
        'src/vecmath.cpp'
    );

    setupCppConfig :targetType =>'DLL' do |cfg|
    end
end

end # module Rakish

