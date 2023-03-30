myDir = File.dirname(File.expand_path(__FILE__));
require "#{myDir}/../build-options.rb";

module Rakish

Rakish::CppProject.new(
	:name 			=> "artd-lib-vecmath",
	:package 		=> "artd",
	:dependsUpon 	=> [ "../artd-lib-logger"]
) do

	cppDefine('BUILDING_artd_lib_vecmath');

	addPublicIncludes('include/artd/*.h');

    addSourceFiles(
    );

    setupCppConfig :targetType =>'DLL' do |cfg|
    end
end

end # module Rakish

