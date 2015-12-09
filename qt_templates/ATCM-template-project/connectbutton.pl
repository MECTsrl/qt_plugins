#!/usr/bin/perl

# open page*.ui
# check if into the section "connections" is presents all buttons with the pageName not empty

# check all the page*.ui files
foreach $file (glob( 'page*.ui' ))
{
	my $page_name = '';
	my $button_name = '';
	my $line = '';
	my @buttonlist;
	print "Elaborating file '" . $file . "'\n";
	open INFILE, "<", $file or die $!;
	open TMP, "+>", undef or die $!;
	while (<INFILE>)
	{
		$line = $_;
		chomp($line);
		$line =~ s/\\//g;
		$line =~ s/^\s+//;
		$line =~ s/\s+$//;	
		# exctract the pagename pageXXX form "<class>pageXXX</class>"
		if ($page_name eq '' && $line =~ /<class>([A-z0-9]+)<\/class>/)
		{
			$page_name = $1;
		}
		# for each button <widget class="ATCMbutton" name="YYYY"> extract the name YYYY and the page name:
		elsif ($line =~ /<widget class="ATCMbutton" name="([A-z0-9]+)">/)
		{
			$button_name = $1;
		}
		elsif ($line =~ /<property name="pageName">/)
		{
			print TMP $line . "\n";
			$line = <INFILE>;
			chomp($line);
			$line =~ s/\\//g;
			$line =~ s/^\s+//;
			$line =~ s/\s+$//;	
			if ($line =~ /<string>([A-z0-9]+)<\/string>/ && $1 ne '')
			{
				push(@buttonlist,$button_name);
			}
			$button_name = "";
		}
		elsif (scalar(@buttonlist) != 0 && $line =~ /<connections>/ )
		{
			while ( ! ($line =~ /<\/connections>/))
			{
				if ($line =~ /<sender>([A-z0-9]+)<\/sender>/)
				{
					my @buttonlist2;
					print "INIZIO" . join(", ", @buttonlist) . "\n";
					print "removing " . $1 . "\n";
					foreach $button (@buttonlist)
					{
						if ($button ne $1)
						{
							push(@buttonlist2,$button);
						}
					}
					@buttonlist = @buttonlist2;
					print "FINE" . join(", ", @buttonlist) . "\n";
				}
				print TMP $line . "\n";
				$line = <INFILE>;
				chomp($line);
				$line =~ s/\\//g;
				$line =~ s/^\s+//;
				$line =~ s/\s+$//;	
			}
		}
		if (($line =~ /<\/connections>/ || $line =~ /<connections\/>/) && scalar(@buttonlist) != 0 )
		{
			foreach $button (@buttonlist)
			{
				print "Connetting button '" . $button . "'\n";
				print TMP "  <connection>\n";
				print TMP "   <sender>" . $button . "</sender>\n";
				print TMP "   <signal>newPage(const char*,bool)</signal>\n";
				print TMP "   <receiver>" . $page_name . "</receiver>\n";
				print TMP "   <slot>goto_page(const char*,bool)</slot>\n";
				print TMP "  </connection>\n";
			}
			print TMP " </connections>\n";
		}
		else
		{
			print TMP $line . "\n";
		}
	}
	close INFILE;

	open INFILE, ">", $file or die $!;

	# Move to the beginning of file
	seek(TMP,0,0);
	# Read contents of the anonymous file
	while (<TMP>) {
		print INFILE $_;
	}
	close TMP;
	close INFILE;
}
