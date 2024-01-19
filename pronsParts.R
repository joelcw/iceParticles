library(ggplot2)
library(plyr)
library(gdata)
library(lme4)


####Read the file of CorpusSearch codes into an R data frame.

foo <- read.delim("~/iceParticles/outputs/pronsParts.ice.treeIDandIDfixed.cod.ooo",header=F,sep=":")


####Give appropriate column names to the columns

colnames(foo) <- c("OV","Clause","Diag","SbjType","Year","Genre","Text","SentNum")

####Throw out all the codes that refer to tokens that are irrelevant for the study. Also throw out Nwe Test translation because it's an outlier, 

"Got up to subsetting"

part.data <- subset(foo, OV != "z" & Clause != "z" & Diag != "z" & SbjType != "z" & Year != "0" & Year != "" & Year != "na" & Text != "" & Text != "z")

####For now, we are only interested in particles and pronoun objs
part.data <- subset(part.data, Diag != "qobj" & Diag != "posobj")


####Make sure R factor groups don't include factors for the irrelevant codes.

part.data <- droplevels(part.data)

"finished droplevels"


####Make sure dates abd 0/1 codes are stored as numbers, and weights

part.data$Year <- as.numeric(as.character(part.data$Year))
part.data$OV <- as.numeric(as.character(part.data$OV))


"finished converting to numeric"

#Make Genre more interpretable
part.data$SimpleGenre <- ifelse(part.data$Genre == "nar", "nar", "other")

partSubOnly.data <- subset(part.data, Clause == "sub")
partSubOnly.data <- droplevels(partSubOnly.data)


p <- ggplot(partSubOnly.data, aes(Year, OV, color=Diag, group=Diag)) + 
  labs(y = "Proportion of OV Diagnostics in Sub Clauses", x = "\nYear") + 
  stat_sum(aes(size=..n.., alpha=.1)) + 
  scale_size_area(max_size=12) + 
  facet_wrap(~SimpleGenre) +
  #stat_smooth(method="glm", family ="binomial")
  stat_smooth() + 
  scale_alpha_continuous(guide="none", limits = c(0,.7)) + 
  scale_color_brewer(palette = "Set1") + 
  ylim(0,1) + 
  theme_bw() + theme(panel.border = element_blank())

ggsave(p, file = "~/iceParticles/pronsPartsSubOnly.png", width = 8, height = 5)

partNarOnly.data <- subset(part.data, SimpleGenre == "nar" & Clause != "invq")
partNarOnly.data <- droplevels(partNarOnly.data)

q <- ggplot(partNarOnly.data, aes(Year, OV, color=Diag, group=Diag)) + 
  labs(y = "Proportion of OV Diagnostics in Narrative Texts", x = "\nYear") + 
  stat_sum(aes(size=..n.., alpha=.1)) + 
  scale_size_area(max_size=12) + 
  facet_wrap(~Clause) +
  #stat_smooth(method="glm", family ="binomial")
  stat_smooth() + 
  scale_alpha_continuous(guide="none", limits = c(0,.7)) + 
  scale_color_brewer(palette = "Set1") + 
  ylim(0,1) + 
  theme_bw() + theme(panel.border = element_blank())

ggsave(q, file = "~/iceParticles/pronsPartsNarOnly.png", width = 8, height = 5)

#binning by 50 years and converting to proportion so we can see anything at all:
partNarOnly.data$Year2 <- floor(partNarOnly.data$Year/50)*50
plot.data <- ddply(partNarOnly.data, .(Year2, Clause, Diag),summarize, ov = mean(OV, na.rm = T), n = sum(!is.na(OV)))

k <- ggplot(plot.data, aes(Year2, ov, color=Diag, group=Diag)) + 
  labs(y = "Proportion of OV in Narrative Texts", x = "\nYear") + 
  #  scale_alpha_continuous(guide="none", limits = c(0,0.1)) +
  scale_size_area(max_size=5) +
  geom_point(aes(size = n)) +
  facet_wrap(~Clause) +
  #stat_smooth(method="glm", family ="binomial")
  stat_smooth() + 
  scale_color_brewer(palette = "Set1") + 
  ylim(0,1) + 
  theme_bw() + theme(panel.border = element_blank())

ggsave(k, file = "~/iceParticles/pronsPartsNarOnlyBinned.png", width = 8, height = 5)

partNarOnly.data$zYear <- scale(partNarOnly.data$Year, center=TRUE, scale=TRUE)

partNarOnly.data <- subset(partNarOnly.data, Diag != "both")
partNarOnly.data <- droplevels(partNarOnly.data)
narOnly.fit <- glmer(OV~(1|Text)+zYear+Clause+Diag+Diag*zYear, data=partNarOnly.data, family=binomial)
summary(narOnly.fit)
